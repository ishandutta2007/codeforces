#include <bits/stdc++.h>

using namespace std;

int main ()
{
int h1, a1, c1, h2, a2;
cin>>h1>>a1>>c1>>h2>>a2;
string a = "HEAL";
string b = "STRIKE";
vector<string> commands;
while (h2>a1)
{
    if (h1<=a2)
    {
        commands.push_back(a); h1 = h1 + c1 - a2;
    }
    else
    {
        commands.push_back(b); h1 = h1 - a2; h2 = h2 - a1;
    }
}
commands.push_back(b);

cout<<commands.size()<<endl;
for (int i = 0; i<commands.size(); i++)
    cout<<commands[i]<<endl;

}