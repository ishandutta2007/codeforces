#include<bits/stdc++.h>
using namespace std;

char a[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool ina(char k)
{
    for (int i = 0; i<6; i++) if (k==a[i]) return true;
    return false;
}

int main()
{
    int g;
    cin>>g;
string s;
cin>>s;
int i = 0;
while (i<g)
{
    if (!ina(s[i])) {cout<<s[i]; i++;}
    else
    {
        cout<<s[i]; i++;
        while ((i<g)&&(ina(s[i]))) i++;
    }
    
}

}