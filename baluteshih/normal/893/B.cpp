#include <iostream>
#define __ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int arr[1000000];

int main()
{
	long long n,x,top=-1;
	for(n=1,x=1;x<=100000;n++,x=((1<<n)-1)*(1<<(n-1))) 
		arr[++top]=x;
	cin >> n;
	while(n%arr[top]) top--;
	cout << arr[top] << "\n"; 
}