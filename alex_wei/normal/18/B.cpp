#include<iostream>
long long n,d,m,l,i;
int main()
{
	std::cin>>n>>d>>m>>l;
	for(i=l;i<n*m;i+=m)if(i+d-i%d<i-l+m||i>n*m-m)std::cout<<i+d-i%d,exit(0);
}