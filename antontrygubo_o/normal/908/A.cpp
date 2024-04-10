#include<iostream>
#include<algorithm>
#include<random>
#include<string>
using namespace std;

int main()
{
string s;
getline (cin, s);
int a = s.length();
int number = 0;
for (int b = 0; b<a; b++)
{
    if ((s[b]=='a')||(s[b]=='e')||(s[b]=='i')||(s[b]=='o')||(s[b]=='u')||(s[b]=='1')||(s[b]=='3')||(s[b]=='5')||(s[b]=='7')||(s[b]=='9')) number++;
}
cout<<number;
}