#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, k;
string a[N], b[N];
string v[4]={"aaaa", "aabb", "abab", "abba"};

char isVowel(char ch)
{
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	n*=4;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]="";
		int vowels=0;
		while(vowels<k && a[i].size())
		{
			char ch=a[i].back();
			b[i]+=ch;
			if(isVowel(ch))
				vowels++;
			a[i].pop_back();
		}
		if(vowels<k)
		{
			cout<<"NO";
			return 0;
		}
		reverse(b[i].begin(), b[i].end());
	}
	for(int pos=0;pos<4;pos++)
	{
		int check=1;
		for(int i=1;i<=n;i+=4)
		{
			for(int p=0;p<4;p++)
			{
				for(int q=p+1;q<4;q++)
				{
					if(v[pos][p]==v[pos][q])
					{
						if(b[i+p]!=b[i+q])
							check=0;
					}
				}
			}
		}
		if(check)
		{
			cout<<v[pos];
			return 0;
		}
	}	
	cout<<"NO";
}