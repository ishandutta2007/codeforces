#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

const int maxn = 4e5 + 5;

char word[maxn];
int wlen;
map<char, int> nxt[maxn];
int leaves[maxn];
bool leaf[maxn];
int passed[maxn];
int tree_sz = 1;
int ptr;
string s;
ll ans = 0;

void add_word(){
	int v = 0;
	ptr = 0;
	F(i, 0, wlen){
		passed[ptr++] = v;
		char c = word[i];
		if(nxt[v].count(c))v = nxt[v][c];
		else{nxt[v][c] = tree_sz++; v = nxt[v][c];}
	}
	passed[ptr++] = v;
	if(leaf[v])ret;
	leaf[v] = true;
	F(i, 0, ptr)leaves[passed[i]]++;
}

void process_word(){
	int v = 0;
	bool checked = false;
	F(i, 0, wlen){
		if(leaves[v] == 1 && v != 0 && !checked){
			int j = i;
			checked = true;
			while(j < wlen && !leaf[v]){
				if(!nxt[v].count(word[j]))break;
				v = nxt[v][word[j++]];
			}
			if(leaf[v] && j != i){ans++; ans += wlen - j; add_word(); ret;}
		}
		char c = word[i];
		if(!nxt[v].count(c))nxt[v][c] = tree_sz++;
		v = nxt[v][c];
		++ans;
	}
	add_word();
}

void parse(){
	wlen = 0;
	F(i, 0, (int)s.length()){
		if(isalpha(s[i]))word[wlen++] = s[i];
		else{
			if(wlen){process_word();}
			wlen = 0;
			++ans;
		}
	}
}

int main(){
	sync;
	while(getline(cin, s)){
		s += ' ';
		parse();
	}
	cout << ans;
	ret 0;
}