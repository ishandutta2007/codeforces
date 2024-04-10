#include <iostream>

using namespace std;

string a,b,c;
int ta[50],tb[50],tc[50], maxh, maxi;

int main()
{
    cin >> a >> b >> c;
    for(int i=0;i<a.length();i++) ta[a[i]-'a']++;
    for(int i=0;i<b.length();i++) tb[b[i]-'a']++;
    for(int i=0;i<c.length();i++) tc[c[i]-'a']++;
    maxh=-1;
    maxi=-1;
    bool mehet=true;
    for(int i=0;mehet;i++) {
        int aktmin=10000;
        for(int j=0;j<50;j++) {
            if(ta[j]-tb[j]*i<0) { mehet=false; break;}
            if(tc[j]==0) continue;
            if(((ta[j]-tb[j]*i)/tc[j])<aktmin) aktmin=(ta[j]-tb[j]*i)/tc[j];
        }
        if(!mehet) break;
        if(aktmin+i>maxi) {
            maxi=aktmin+i;
            maxh=i;
        }
    }
    for(int i=0;i<maxh;i++) cout << b;
    for(int i=0;i<maxi-maxh;i++) cout << c;
    for(char ch='a'; ch<='z';ch++) {
        for(int i=0;i<ta[ch-'a']-maxh*tb[ch-'a']-(maxi-maxh)*tc[ch-'a'];i++) cout << ch;
    }
    return 0;
}