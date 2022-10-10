//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 100002
#define MOD 1000000007

	LLI T,n,in,i,m,j,cnt,l,r,ans,a;
	vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[101];
    cin>>s;

    LLI l=strlen(s);
    LLI ty=s[0]-'0';
    LLI cnt=1;
    for(int i=1;i<l;++i)
    {
        if(ty==s[i]-'0')
            cnt++;
        else
        {
            ty=s[i]-'0';
            cnt=1;
        }
        if(cnt>=7)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
	return 0;
}