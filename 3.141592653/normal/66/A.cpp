#include<cstdio>
#include<iostream>
using namespace std;
string b1="127z",b2="128z",s1="32767z",s2="32768z",i1="2147483647z",i2="2147483648z",l1="9223372036854775807z",l2="9223372036854775808z";
string t1="byte",t2="short",t3="int",t4="long",t5="BigInteger";
bool isnaga;
int main()
{
	string comp;
	cin>>comp;
	int l=comp.size();
	if(comp[0]=='-')
	{
		int i;
		for(i=1;i<l;i++)
			comp[i-1]=comp[i];
		comp[l-1]=0;
		isnaga=true,l--;
	}
	if(l<3)cout<<t1<<endl;
	else if(l==3)
	{
		if(isnaga)
		{
			if(comp>b2)cout<<t2<<endl;
			else cout<<t1<<endl;
		}
		else
		{
			if(comp>b1)cout<<t2<<endl;
			else cout<<t1<<endl;
		}
	}
	else if(l<5)cout<<t2<<endl;
	else if(l==5)
	{
		if(isnaga)
		{
			if(comp>s2)cout<<t3<<endl;
			else cout<<t2<<endl;
		}
		else
		{
			if(comp>s1)cout<<t3<<endl;
			else cout<<t2<<endl;
		}
	}
	else if(l<10)cout<<t3<<endl;
	else if(l==10)
	{
		if(isnaga)
		{
			if(comp>i2)cout<<t4<<endl;
			else cout<<t3<<endl;
		}
		else
		{
			if(comp>i1)cout<<t4<<endl;
			else cout<<t3<<endl;
		}
	}
	else if(l<19)cout<<t4<<endl;
	else if(l==19)
	{
		if(isnaga)
		{
			if(comp>l2)cout<<t5<<endl;
			else cout<<t4<<endl;
		}
		else
		{
			if(comp>l1)cout<<t5<<endl;
			else cout<<t4<<endl;
		}
	}
	else cout<<t5<<endl;
}