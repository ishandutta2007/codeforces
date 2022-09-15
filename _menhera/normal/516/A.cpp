#include<cstdio>
#include<vector>
using namespace std;
int ans[100];
int main()
{
	int n;
	char str[1000];
	scanf("%d%s",&n,str);
	for(int i=0;i<n;i++)
	{
		switch(str[i])
		{
			case '9':
				ans[7]++;
				ans[3]+=2;
				ans[2]++;
				break;
			case '8':
				ans[7]++;
				ans[2]+=3;
				break;
			case '7':
				ans[7]++;
				break;
			case '6':
				ans[5]++;
				ans[3]++;
				break;
			case '5':
				ans[5]++;
				break;
			case '4':
				ans[3]++;
				ans[2]++;
				ans[2]++;
				break;
			case '3':
				ans[3]++;
				break;
			case '2':
				ans[2]++;
				break;
			default:
				break;
		}
	}
	for(int i=9;i>=2;i--)
	{
		for(int j=0;j<ans[i];j++)
			printf("%d",i);
	}
	return 0;
}
//9!=7! *3!*3!*2!
//8!=7! *2!*2!*2!
//7!=7!
//5!=5!
//6!=5!*3!
//4!=3!*2!*2!
//3!=3!
//2!=2!