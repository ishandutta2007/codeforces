#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  F                     first                 
#define  S                     second
#define  endl                  "\n"

const ll   N     =  3e+5+5;
const ll   MAX   =  1e18;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,x,res=MAX,tmp;

struct TrieNode{ 
    struct TrieNode* children[2]; 
    bool isEndOfWord; 
}; 
  
struct TrieNode* getNode(){ 
    struct TrieNode* pNode = new TrieNode; 
    pNode->isEndOfWord = false; 
    for(int i = 0; i < 2; i++) pNode->children[i] = NULL; 
    return pNode; 
} 
 
void insert(struct TrieNode* root, string key){ 
    struct TrieNode* pCrawl = root; 
  
    for(int i = 0; i < 32; i++){
        ll index = key[i]-'0'; 
        if(!pCrawl->children[index]) pCrawl->children[index] = getNode(); 
        pCrawl = pCrawl->children[index]; 
    } 
 
    pCrawl->isEndOfWord = true; 
} 
 
bool isEmpty(TrieNode* root){ 
    for(int i = 0; i < 2; i++){if(root->children[i]) return false;} 
	return true; 
}

string decToBinary(ll n) { 
	string s;
    for(ll i = 31; i >= 0; i--) { 
		ll k = n >> i; 
		if (k&1) s+="1"; 
		else s+="0"; 
	}
	return s; 
} 

void dfs(struct TrieNode * t, ll poww){
	if(t->isEndOfWord == true){
		res = min(res,tmp);
		return;
	}
	if(t->children[0] == NULL){ 
		dfs(t->children[1],poww-1);
	}
	else if(t->children[1] == NULL){ 
		dfs(t->children[0],poww-1);
	}
	else{
		tmp += pow(2,poww);
		dfs(t->children[0],poww-1);
		dfs(t->children[1],poww-1);
		tmp -= pow(2,poww);
	}

}
int main(){ 
	struct TrieNode *t = getNode();
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>x;
		insert(t,decToBinary(x));
	}
	dfs(t,31);
	cout<<res<<endl;
}