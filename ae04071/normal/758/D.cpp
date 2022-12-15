#include <stdio.h>
#include <cstring>
#include <stack>

typedef long long lli;

char str[80];
int arr[80];
lli n;

lli Power(lli a,int t)
{
	lli res=1;
	for(int i=0;i<t;i++) 
		res*=a;
	//printf("%lld\n",res);
	return res;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",str);

	int len=strlen(str);
	for(int i=0;i<len;i++)
		arr[i]=str[i]-'0';

	int fi=len;
	lli sum=0, res=0;
	int a=0, idx=0;
	for(int i=len-1;i>=0;i--) {
		if(sum+arr[i]*Power(10ll, a)>=n) {
			{
			//	printf("%lld\n",sum);

				res+=sum*Power(n,idx);
				idx++;
				if(sum==0) idx--;
			//	printf("%lld %d\n",idx, fi);

				a=1;
				sum=arr[i];
				//printf("ff: %d\n", fi);
				if(fi!=i+1) {
					int tt=i+1;
					while(tt<fi && sum*10<n) {
						sum*=10;
						tt++; a++;
					}
					idx+=(fi-tt
						);
				}
				fi=i;
			}
		}
		else {
			sum+=arr[i]*Power(10ll,a);
			a++;
			if(arr[i]!=0) {
				fi=i;
				//printf("11\n");
			}
		}
		//printf("%lld\n", sum);
	}
	res+=sum*Power(n,idx);
	idx++;

	printf("%lld\n",res);

	return 0;
}