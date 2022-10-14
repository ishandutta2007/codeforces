// 
// 
// 
// 
// 
// 


#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define f first
#define s second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
string s="";
void permute(string s , string answer)
{
    if(s.length() == 0)
    {
        cout<<answer<<"  ";
        return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0,i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        permute(rest , answer+ch);
    }
 
}
bool isSubstring(string s1, string s2)
{
	return s1.find(s2)==-1?0:1;
    // return 0;
}

bool printAllKLengthRec(string set, string prefix, int n, int k)
{
     
    if (k == 0)
    {
        if(!isSubstring(s,prefix)){
        	cout<<prefix<<endl;
			return 1;
        }
		return 0;
    }
 	bool ans=0;
    for (int i = 0; i < n; i++)
    {
        string newPrefix;
         
        newPrefix = prefix + set[i];
        ans=ans||printAllKLengthRec(set, newPrefix, n, k - 1);
        if(ans)return 1;
    }
 	return ans;
}
 
bool printAllKLength(string set, int k,int n)
{
    if(printAllKLengthRec(set, "", n, k))return 1;
    return 0;
}
int32_t main()
{
	// aeh();
	int t;cin>>t;
	while(t--)	
	{
		int n;cin>>n;
		cin>>s;	
		string p="";
		char ch='a';
		fi(26)
		{
			p+=ch;ch++;
		}
		fi(26){
			if(printAllKLength(p,i+1,26))break;
		}

	}
}

int mpow(int base, int exp)
{
	base %= mod;
	int result = 1;
	while (exp > 0)
	{
		if (exp & 1)result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}