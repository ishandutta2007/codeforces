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
    LLI T,n,in,i,m,j,k;
    vector <LLI> a;
    string s;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    //cout<<n<<m<<k<<endl;
    j=0;
    string a="hello";
    fo(i,s.size())
    {
    	if(j==5)
    		break;
    	if(s[i]==a[j])
    		j++;
	}
	if(j==5)
		cout<<"YES";
	else
		cout<<"NO";
    return 0;
}