#include <iostream>
#include <string>

using namespace std;

struct lex{
	bool zero,one,good;
} zero,one,que;

int r=0;
string s;

void ini(void){
	zero.zero=1;
	zero.one=zero.good=0;
	
	one.one=1;
	one.zero=one.good=0;
	
	que.one=que.zero=0;
	que.good=1;
}

lex or1(lex a, lex b){
	lex x;
	x.one=a.one||b.one||(a.good&&b.good);
	x.zero=a.zero&&b.zero;
	x.good=(a.good&&b.good)||(a.good&&b.zero)||(a.zero&&b.good);
	return x;
}

lex and1(lex a, lex b){
	lex x;
	x.one=a.one&&b.one;
	x.zero=a.zero||b.zero||(a.good&&b.good);
	x.good=(a.good&&b.good)||(a.good&&b.one)||(a.one&&b.good);
	return x;
}

lex xor1(lex a, lex b){
	lex x;
	x.one=(a.one&&b.zero)||(a.zero&&b.one)||(a.good&&b.good);
	x.zero=(a.one&&b.one)||(a.zero&&b.zero)||(a.good&&b.good);
	x.good=((a.one||a.zero)&&b.good)||(a.good&&(b.one||b.zero));
	return x;
}


lex parse(){
	char ch,op;
	lex l,r;
	
	cin>>ch;
	
	if (ch=='0')
	return zero;
	
	if (ch=='1')
	return one;
	
	if (ch=='?')
	return que;
	
	l=parse();
	cin>>op;
	r=parse();
	cin>>ch;
	
	if (op=='|')
	return or1(l,r);
	
	if (op=='&')
	return and1(l,r);
	
	return xor1(l,r);	
}

int main()
{
	ios_base::sync_with_stdio(0);
	ini();
	cin>>s;
	cout<<(parse().good ? "YES\n":"NO\n");
	return 0;
}