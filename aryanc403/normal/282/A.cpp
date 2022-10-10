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

	LLI T,n,in,i,m,j,cnt,l;
	string s;
	vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[4];
    LLI x=0;
    scanf(" %d",&T);

    while(T--)
    {
        scanf(" %s",s);

        if(s[0]=='-'||s[1]=='-')
        {
            x--;
        }
        else
        {
            x++;
        }
    }

    cout<<x;

	return 0;
}