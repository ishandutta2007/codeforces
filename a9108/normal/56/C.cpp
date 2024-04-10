#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

char s[2000];
int n,m;
vector<int> son[2000];
string name[2000];

int maketr(int now,int i){
	son[now].clear();
	name[now]="";
	for (;i<n&&isalpha(s[i]);i++) name[now]+=s[i];
	if (s[i]=='.') return i+1;
	i++;
	for (;i<n;){
		m++;
		son[now].PB(m);
		i=maketr(m,i);
		if (s[i]=='.') return i+1;
		else i++;
	}
}

int getans(int i,string s){
	int ans=0;
	if (name[i]==s) ans++;
	for (int z=0;z<son[i].size();z++) ans+=getans(son[i][z],s);
	return ans;
}

int getans(int i){
	int ans=0;
	for (int z=0;z<son[i].size();z++) ans+=getans(son[i][z])+getans(son[i][z],name[i]);
	return ans;
}

int main(){
	scanf("%s",s);
	n=strlen(s);
	m=0;
	maketr(0,0);
	printf("%d\n",getans(0));
	//printf("%d %d\n",maketr(0,0),strlen(s));
	return 0;
}