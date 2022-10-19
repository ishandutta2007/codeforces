#include <bits/stdc++.h>
#define maxn 4004000
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 998244353  
#define debug(args...) //printf(args)
using namespace std;
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define MAXN 4004000
int d1[MAXN];//d1[i] = max odd palindrome centered on i
int d2[MAXN];//d2[i] = max even palindrome centered on i
//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301
void manacher(string& s){
	int l=0,r=-1,n=s.size();
	fore(i,0,n){
		int k=i>r?1:min(d1[l+r-i],r-i);
		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
		d1[i]=k--;
		if(i+k>r)l=i-k,r=i+k;
	}
	l=0;r=-1;
	fore(i,0,n){
		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
		while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
		d2[i]=--k;
		if(i+k-1>r)l=i-k,r=i+k-1;
	}
}

char str[maxn];

string solve(string s){
    
    int n = s.length();
    manacher(s);
    int u = -1;
    
    while(u+1 < n && s[u+1] == s[n-u-2]) u++;
    
    int A = -1, B = -1;
    
    debug("u %d\n",u);
    
    for(int i=0;i<n;i++){
        
        int ini = i - d1[i]+1;
        int end = i + d1[i]-1;
        if(u + 1 >= ini){
            if(end+1 + ini > A+B && ini+end+1 <= n){
                A = end+1;
                B = ini;
                debug("i %d ini %d end %d\n",i,ini,end);
            }
        }
        
    }
    
   for(int i=0;i<n;i++){
        
        int ini = i - d2[i];
        int end = i + d2[i]-1;
        if(u+1 >= ini){
            if(end+1 + ini > A+B && ini+end+1 <= n){
                A = end+1;
                B = ini;
            }
        }
        
        
    }
    
    debug("got %d %d\n",A,B);
    
    
    string ret;
    for(int i=0;i<A;i++) ret.pb(s[i]);
    for(int i=n-B;i<n;i++) ret.pb(s[i]);
    return ret;
    
}
 

int main(){
    int nt;
    scanf("%d",&nt);
    while(nt--){
        scanf (" %s",str);
        string ss = (string) str;
       
        int n = strlen(str);
        
        string A = solve(ss);
        reverse(str,str+n);
        ss = (string) str;
        string B = solve(ss);
        reverse(B.begin(), B.end());
        if(A.length() > B.length())
            printf("%s\n",A.c_str());
        else
            printf("%s\n",B.c_str());
        
        
    
    }
    
}