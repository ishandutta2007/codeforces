#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

unsigned long long readTimeStampCounter() {
	unsigned a = 123456789, b = 987654321;
#ifdef __GNUC__
	asm (
		"rdtsc;\n\t"
		: "=d" (a), "=a" (b)
	);
#else
	__asm {
		rdtsc;
		mov a, edx;
		mov b, eax;
	};
#endif
	return (unsigned long long)a << 32 | b;
}
unsigned xor128() {
	static unsigned x = 123456789, y = 362436069,
		z = (unsigned)(readTimeStampCounter() >> 32), w = (unsigned)readTimeStampCounter();
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

struct PolynomialHash {
	static const int NumMods = 5;
	static const unsigned Mods[NumMods];
	typedef unsigned long long ull;
	struct Hash {
		unsigned hs[NumMods];
		Hash() { for(int k = 0; k < NumMods; ++ k) hs[k] = 0; }
		bool operator==(const Hash &that) const {
			bool res = true;
			for(int k = 0; k < NumMods; ++ k)
				res &= hs[k] == that.hs[k];
			return res;
		}
		bool operator<(const Hash &that) const {
			for(int k = 0; k < NumMods; ++ k)
				if(hs[k] != that.hs[k])
					return hs[k] < that.hs[k];
			return false;
		}
	};
	static unsigned seeds[NumMods];
	static std::vector<Hash> powh;

	static void initSeeds() {
		for(int k = 0; k < NumMods; ++ k) {
			unsigned x;
			do x = xor128(); while(x == 0 || x >= Mods[k]);
			seeds[k] = x;
		}
	}
	static void precomputePowerTable(int newSize) {
		if((int)powh.size() >= newSize) return;
		if(seeds[0] == 0) initSeeds();
		int oldSize = powh.size();
		powh.resize(newSize);
		if(oldSize == 0)
			for(int k = 0; k < NumMods; ++ k) powh[0].hs[k] = 1;
		for(int i = std::max(1, oldSize); i < newSize; i ++) for(int k = 0; k < NumMods; ++ k)
			powh[i].hs[k] = (ull)powh[i-1].hs[k] * seeds[k] % Mods[k];
	}
};
const unsigned PolynomialHash::Mods[PolynomialHash::NumMods] = { 2147483647U, 2147483629U, 2147483587U, 2147483579U, 2147483563U };
unsigned PolynomialHash::seeds[PolynomialHash::NumMods];
std::vector<PolynomialHash::Hash> PolynomialHash::powh;


struct SubstringHash : PolynomialHash {
	std::vector<Hash> preh;

	template<typename V>
	void init(const V &v, int n) {
		precomputePowerTable(n+1);
		preh.resize(n+1);
		preh[0] = Hash();
		for(int i = 0; i < n; i ++) for(int k = 0; k < NumMods; ++ k)
			preh[i+1].hs[k] = ((ull)preh[i].hs[k] * seeds[k] % Mods[k] + v[i]) % Mods[k];
	}
	Hash hash(int j) const {
		return preh[j];
	}
	Hash hash(int i, int j) const {
		if(i == 0) return hash(j);
		Hash res;
		for(int k = 0; k < NumMods; ++ k) {
			unsigned x = preh[j].hs[k] + Mods[k] - (unsigned)((ull)preh[i].hs[k] * powh[j - i].hs[k] % Mods[k]);
			res.hs[k] = x >= Mods[k] ? x - Mods[k] : x;
		}
		return res;
	}
	Hash append(const Hash &h, const Hash &g, int glen) const {
		Hash res;
		for(int k = 0; k < NumMods; ++ k) {
			unsigned x = (unsigned)((ull)h.hs[k] * powh[glen].hs[k] % Mods[k]) + g.hs[k];
			res.hs[k] = x >= Mods[k] ? x - Mods[k] : x;
		}
		return res;
	}
};

struct Cfg {
	typedef SubstringHash::Hash Key;
	typedef unsigned Index;
	Key emptyKey() const { return SubstringHash::Hash(); }
	Index hash(const Key &key) const { return key.hs[0]; }
	bool equals(const Key &key1, const Key &key2) const { return key1 == key2; }
	bool isEmptyKey(const Key &key) const { return key == emptyKey(); }
};

struct HashTable {
public:
	typedef Cfg Config;
	typedef Config::Key Key;
	typedef Config::Index Size, Index;

	Key emptyKey() const { return config.emptyKey(); }

	Index hash(const Key &key) const { return config.hash(key); }

	bool equals(const Key &key1, const Key &key2) const { return config.equals(key1, key2); }
	bool isEmptyKey(const Key &key) const { return config.isEmptyKey(key); }

public:
	HashTable(Config config = Config(), Size minCapacity = 0): table(NULL), tableSize(0), numElements(0), config(config) {
		reserve(minCapacity);
	}

	HashTable(const HashTable &that): table(NULL), tableSize(0), numElements(0), config(that.config) {
		*this = that;
	}

	HashTable &operator=(const HashTable &that) {
		if(this == &that) return *this;
		numElements = 0;	//reallocate
		reserve(that.numElements);
		clear();
		copyTable(that.table, that.table + that.tableSize);
		numElements = that.numElements;
		return *this;
	}

	~HashTable() {
		delete[] table;
		table = NULL;
	}

	void swap(HashTable &that) {
		std::swap(table, that.table);
		std::swap(tableSize, that.tableSize);
		std::swap(numElements, that.numElements);
	}

	void clear() {
		for(Key *p = table, *pEnd = p + tableSize; p != pEnd; ++ p)
			if(!isEmptyKey(*p))
				*p = emptyKey();
		numElements = 0;
	}

public:
	bool empty() const { return numElements == 0; }
	Size size() const { return numElements; }
	Size capacity() const { return calculateCapacity(tableSize); }

	bool reserve(Size minCapacity) {
		if(minCapacity <= calculateCapacity(tableSize))
			return false;
		Size newSize = tableSize == 0 ? 4 : tableSize * 2;
		while(calculateCapacity(newSize) < minCapacity)
			newSize *= 2;
		reallocate(newSize);
		return true;
	}

private:
	static Size calculateCapacity(Size tableSize) {
		return tableSize * 3 / 4;
	}

	void copyTable(const Key *p, const Key *pEnd) {
		for(; p != pEnd; ++ p) {
			if(!isEmptyKey(*p)) {
				Index index;
				bool found = probe(*p, index);
				assert(!found);
				table[index] = *p;
			}
		}
	}

	void reallocate(Size newSize) {
		assert(newSize > tableSize && (newSize & (newSize - 1)) == 0);
		Key *oldTable = table;
		Size oldSize = tableSize;
		table = new Key[newSize];
		tableSize = newSize;
		std::fill(table, table + tableSize, emptyKey());
		if(numElements != 0)
			copyTable(oldTable, oldTable + oldSize);
		delete[] oldTable;
	}

private:
	//key
	bool probe(const Key &key, Index &resIndex) const {
		assert(numElements < tableSize);
		Size mask = tableSize - 1;
		Index h = hash(key) & mask, numProbes = 0;
		while(1) {
			const Key &k = table[h];
			if(isEmptyKey(k)) {
				resIndex = h;
				return false;
			}else if(equals(k, key)) {
				resIndex = h;
				return true;
			}
			++ numProbes;
			h = (h + numProbes) & mask;
			assert(numProbes < tableSize);
		}
	}

public:
	bool count(const Key &key) const {
		if(empty()) return false;
		Index dummy;
		return probe(key, dummy);
	}
	
	bool insert(const Key &key) {
		reserve(numElements + 1);
		Index index;
		bool found = probe(key, index);
		if(found) return false;
		table[index] = key;
		++ numElements;
		return true;
	}

	const Key *find(const Key &key) const {
		if(empty()) return NULL;
		Index index;
		bool found = probe(key, index);
		if(!found) return NULL;
		return &table[index];
	}

	Key *find(const Key &key) {
		return const_cast<Key*>(find(key));
	}

	Key &findInsert(const Key &key) {
		reserve(numElements + 1);
		Index index;
		bool found = probe(key, index);
		if(!found) {
			table[index] = key;
			++ numElements;
		}
		return table[index];
	}

private:
	const Config config;
	Key *table;
	Size tableSize;		//power of two (or 0)
	Size numElements;	//number of nonempty elements
};


int main() {
	int n;
	scanf("%d", &n);
	char *S = new char[n + 1], *T = new char[n + 1];
	scanf("%s", S);
	scanf("%s", T);
//rep(i,n)S[i]='a';S[n]=0;
//rep(i,n)T[i]='a';T[n]=0;
	SubstringHash subhS, subhT, alphas[26];
	subhS.init(S, n);
	subhT.init(T, n);
	rep(a, 26)
		alphas[a].init(vector<char>(1, 'a' + a), 1);
	typedef SubstringHash::Hash Hash;
	HashTable hashes; hashes.reserve((n+1) * 26);
	rer(i, 0, n) rep(a, 26) {
		Hash h = subhS.hash(i);
		h = subhS.append(h, alphas[a].hash(1), 1);
		h = subhS.append(h, subhS.hash(i, n), n - i);
		hashes.insert(h);
	}
	HashTable words; words.reserve((n+1) * 26);
	rer(i, 0, n) rep(a, 26) {
		Hash h = subhT.hash(i);
		h = subhT.append(h, alphas[a].hash(1), 1);
		h = subhT.append(h, subhT.hash(i, n), n - i);
		if(hashes.count(h))
			words.insert(h);
	}
	int ans = words.size();
	printf("%d\n", ans);
	return 0;
}