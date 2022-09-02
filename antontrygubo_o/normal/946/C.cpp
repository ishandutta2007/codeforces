#include<bits/stdc++.h>
using namespace std;



int main()
{
string s;
cin>>s;
bool k = true;
int len = s.length();
int currentletter = 0;
int idx = 0;
string answer;
answer.clear();
while ((idx<len)&&(currentletter<26))
{
    if (int(s[idx])-97<=currentletter) {answer+=char(currentletter+97); currentletter++;}
    else answer+=s[idx];
    idx++;
}
if (currentletter==26) 
{
   cout<<answer; for (int i = idx; i<len; i++) cout<<s[i];
}
else cout<<-1;
    
}