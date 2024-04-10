#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'
using namespace std;
char ar[140000];

int getCost(int L , int R , char ch)
{
	int cnt = 0;
	for(int i=L;i<=R;i++)
	if(ar[i] != ch) cnt++;
	
	return cnt;
}

int getMin(int L , int R , char ch)
{
	if(L == R)
	{
		if(ar[L] == ch) return 0;
		else			return 1;
	}
	
	int mid = (L + R) / 2;
	
	return min(getCost(L , mid , ch) + getMin(mid + 1 , R , ch+1) ,
	 
				getCost(mid + 1 , R , ch) + getMin(L , mid , ch+1));
}

int main()
{
	int t , n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		REP(i , n) cin>>ar[i];
		
		cout<<getMin(1 , n , 'a')<<endl;
	}
}