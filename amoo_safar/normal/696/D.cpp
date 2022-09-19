// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e3 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 32;


template<typename T>
struct Matrix {
public:
	int rows, columns;
	vector< vector<T> > A;
	vector<T>& operator [](int idx){
		return A[idx];
	}
	Matrix(int n, int m, T _fill = -Inf){
		rows = n; columns = m;
		A.resize(n, vector<T> (m, _fill));
	}
	Matrix(){
		A.clear();
	}
	void resize(int n, int m){
		rows = n; columns = m;
		A.resize(n, vector<T> (m));	
	}
	void operator = (vector< vector<T> > data){
		rows = data.size();
		columns = data[0].size();
		for(int i = 0; i < rows; i++)
			assert(((int) data[i].size()) == columns);
		A = data;
	}
	Matrix(vector< vector<T> >& data){
		*this = data;
	}
	Matrix operator * (Matrix& B){
		Matrix res(rows, B.columns);
		assert(columns == B.rows);
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < B.columns; j++)
				for(int k = 0; k < columns; k++)
					res[i][j] = max(res[i][j], (A[i][k] + B[k][j]));
		return res;
	}
	void operator *= (Matrix& B){
		*this = *this * B;
	}
	
	template<typename U>
	Matrix operator ^ (U power){
		if(power == 1) return *this;
		
		Matrix res(rows, columns);
		Matrix binary_pow(A);
		assert(rows == columns);
		for(int i = 0; i < rows; i++) res[i][i] = 0;
		
		while(power){
			if(power & 1) res *= binary_pow;
			binary_pow *= binary_pow;
			power >>= 1;
		}
		return res;
	}
	template<typename U>
	void operator ^= (U B){
		*this = *this ^ B;
	}
	
	friend ostream& operator << (ostream& os, Matrix& M){
		for(int i = 0; i < M.rows; i++){
			for(int j = 0; j < M.columns; j++) os << M[i][j] << ' ';
			os << '\n';
		}
		return os;
	}
	friend istream& operator >> (istream& is, Matrix& M){
		for(int i = 0; i < M.rows; i++)
			for(int j = 0; j < M.columns; j++) is >> M[i][j];
		return is;
	}
};



struct AhoCorasick {
	static const int _Sig = 26;
	static const int _N = 2e5 + 10;

	int G[_N][_Sig], Sz;
	int F[_N], Que[_N];
	ll val[_N];

	AhoCorasick (){
		memset(G, 0, sizeof G);
		memset(F, 0, sizeof F);
		memset(val, 0, sizeof val);
		Sz = 1;
	}
	int Add(string &S, ll v){
		int nw = 0;
		for(auto &c : S){
			if(!G[nw][c - 'a'])
				G[nw][c - 'a'] = Sz ++;
			nw = G[nw][c - 'a'];
		}
		val[nw] += v;
		return nw;
	}
	void Build(){
		int nw, l = 0, r = 0;
		for(int i = 0; i < _Sig; i++)
			if(G[0][i])
				Que[r ++] = G[0][i];
		while(r - l){
			nw = Que[l ++];
			for(int i = 0; i < _Sig; i++)
				if(G[nw][i])
					F[G[nw][i]] = G[F[nw]][i], Que[r ++] = G[nw][i];
				else
					G[nw][i] = G[F[nw]][i];
		}
		for(int i = 0; i < r; i++)
			val[ Que[i] ] += val[F[ Que[i] ]];
	}
	int Size(){ return Sz; }
	ll Solve(ll l){
		Matrix<ll> A(Sz, Sz);
		for(int i = 0; i < Sz; i++){
			for(int j = 0; j < _Sig; j++)
				A[i][G[i][j]] = val[G[i][j]];
		}
		A ^= l;
		return *max_element(all(A[0]));
	}
} Aho;

int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; ll l;
	cin >> n >> l;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	str s;
	for(int i = 0; i < n; i++){
		cin >> s;
		Aho.Add(s, a[i]);
	}
	Aho.Build();
	cout << Aho.Solve(l) << '\n';
	return 0;
}