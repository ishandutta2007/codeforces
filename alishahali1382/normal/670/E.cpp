#include <bits/stdc++.h>

using namespace std;

const int MAXN=500 * 1000 + 10;


int n, m, p;
char tmp;
char s[MAXN];
int nxt[MAXN];
int prv[MAXN];
int cop[MAXN];

stack<int> st;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m>>p;
	//p--;
	for (int i=1; i<=n; i++){
		cin>>s[i];
		if (s[i]=='(') st.push(i);
		else {
			cop[st.top()]=i;
			cop[i]=st.top();
			st.pop();
		}
		nxt[i]=i+1;
		prv[i]=i-1;
	}
	nxt[n+1]=n+1;
	prv[0]=0;
	for (int i=0; i<m; i++){
		cin>>tmp;
		if (tmp=='R'){
			if (nxt[p]<=n) p=nxt[p];
			continue ;
		}
		if (tmp=='L'){
			if (prv[p]) p=prv[p];
			continue ;
		}
		if (cop[p]>p) p=cop[p];
		
		if (nxt[p]==n+1){
			nxt[prv[cop[p]]]=n+1;
			p=prv[cop[p]];
			if (!p) return 0;
			continue ;
		}
		
		prv[nxt[p]]=prv[cop[p]];
		nxt[prv[cop[p]]]=nxt[p];
		if (nxt[p]<=n) p=nxt[p];
		else p=prv[p];
		if (!p) return 0;
	}
	while (prv[p]) p=prv[p];
	while (nxt[p]<=n){
		cout<<s[p];
		p=nxt[p];
	}
	cout<<s[p]<<endl;
	
	
	return 0;
}