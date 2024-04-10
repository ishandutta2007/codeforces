#include <iostream>
#include <vector>
using namespace std;

long long n,m,k,ans,mm;
char a[100000];
bool te(char x)
{
	if(x>='a' && x<='z')
		return true;
	return false;
}
vector<int> b;
int main()
{
	int i,j;
	cin>>a;
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]-'0'>=0 && a[i]-'0'<=9)
		{
			if((te(a[i+2]) || i+2>=n) && a[i-1]=='.')
			{
				m*=10;
				m+=a[i]-'0';
				m*=10;
				m+=a[i+1]-'0';
				i+=1;
			}
			else
			{
				for(j=i;j<n;j++)
				{
					if(a[j]=='.' || te(a[j]))
						break;
					k*=10;
					k+=a[j]-'0';
				}
				i=j-1;
			}
		}
		else
		{
			if(a[i]!='.' && te(a[i]))
			{
				ans+=k;
				k=0;
				mm+=m;
				m=0;
			}
		}
	}
	mm+=m;
	ans+=k;
	int copy=mm;
	mm=mm%100;
	ans+=copy/100;
	while(ans)
	{
		b.push_back(ans%10);
		ans/=10;
	}
	bool gg=false;
	int bs=b.size();
	for(i=bs-1;i>=(bs-bs%3);i--)
	{
		cout<<b[i];
		gg=true;
	}
	if((!mm && bs/3==0) || (bs%3==0 && bs!=0))
		goto kov;
	if(bs)
		cout<<'.';
	if(!bs)
		cout<<"0.";
	int bo=0;
	gg=false;
	kov:
	for(i=bs-1-bs%3;i>=0;i--)
	{
		if(bo==3)
		{
			bo=0;
			cout<<'.';
		}
		bo++;
		cout<<b[i];
		gg=true;
	}
	if(mm && gg)
	{
		cout<<'.';
		if(mm<=9)
			cout<<'0'<<mm;
		else
			cout<<mm;
	}
	if(mm && !gg)
	{
		if(mm<=9)
			cout<<'0'<<mm;
		else
			cout<<mm;
	}
	cout<<endl;
	return 0;
}