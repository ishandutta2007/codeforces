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
#define MAX 1000002
#define MOD 1000000007
    LLI T,n,in,i,m,j,cnt[26][26],l;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>l;
	cin>>s;
    //cout<<s<<endl;
    //LLI l=s.size();
    for(i=0;i<l-1;++i)
    {
        cnt[s[i]-'A'][s[i+1]-'A']++;
    }
    
    m=-1;
    pair <LLI,LLI> c;
    c=mp(0,0);
    for(i=0;i<26;++i)
    for(j=0;j<26;++j)
    {
        if(cnt[i][j]>m)
        {
            c=mp(i,j);
            m=cnt[i][j];
        }
    }
    cout<<(char)(c.X+'A')<<(char)(c.Y+'A');
    return 0;
}