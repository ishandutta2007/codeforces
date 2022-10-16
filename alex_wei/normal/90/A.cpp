#include<bits/stdc++.h>
using namespace std;
int r,g,b,k;
int main()
{
	cin>>r>>g>>b;
	while(r>0||g>0||b>0){
		r-=2;
		k++;
		if(r<1&&g<1&&b<1)break;
		g-=2;
		k++;
		if(r<1&&g<1&&b<1)break;
		b-=2;
		k++;
		if(r<1&&g<1&&b<1)break;
	}
	cout<<k+29;
    return 0;
}