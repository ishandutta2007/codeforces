#include<bits/stdc++.h>
using namespace std;
int a1,a2,t;
int main()
{
	cin>>a1>>a2;
	while(1){
		if(a1<1||a2<1||a1==1&&a2==1)break;
		if(a1<3)a1++,a2-=2;
		else a2++,a1-=2;
		t++;
	}
	cout<<t;
    return 0;
}