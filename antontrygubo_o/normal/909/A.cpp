#include<iostream>
#include<algorithm>
#include<random>
#include<string>
using namespace std;

int main()
{
    string s;
    getline (cin, s);
int i = 0;
while (s[i]!=' ') i++;
char c = s[i+1];
int j = 1;
cout<<s[0];
while ((j<i)&&s[j]<c) {cout<<s[j]; j++;}
cout<<c;
}