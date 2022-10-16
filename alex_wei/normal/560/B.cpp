#include <bits/stdc++.h>
using namespace std;
int a1,a2,a3,b1,b2,b3; 
int main(){
	cin>>a1>>b1>>a2>>b2>>a3>>b3;
	if(a2+a3<=a1&&max(b2,b3)<=b1)puts("YES"),exit(0);
	swap(a2,b2);
	if(a2+a3<=a1&&max(b2,b3)<=b1)puts("YES"),exit(0);
	swap(a3,b3);
	if(a2+a3<=a1&&max(b2,b3)<=b1)puts("YES"),exit(0);
	swap(a2,b2);
	if(a2+a3<=a1&&max(b2,b3)<=b1)puts("YES"),exit(0);
	swap(a1,b1);
	if(a2+a3<=a1&&max(b2,b3)<=b1)puts("YES"),exit(0);
	swap(a2,b2);
	if(a2+a3<=a1&&max(b2,b3)<=b1)puts("YES"),exit(0);
	swap(a3,b3);
	if(a2+a3<=a1&&max(b2,b3)<=b1)puts("YES"),exit(0);
	swap(a2,b2);
	if(a2+a3<=a1&&max(b2,b3)<=b1)puts("YES"),exit(0);
	puts("NO");
	return 0;
}