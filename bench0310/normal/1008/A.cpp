#include <iostream>

using namespace std;

bool vowel(char a);

int main()
{
    string b;
    cin >> b;
    bool correct=1;
    for(unsigned int i=1;i<b.size();i++)
    {
        if(vowel(b[i-1]) || b[i-1]=='n') continue;
        if(vowel(b[i])) continue;
        correct=0;
        break;
    }
    if((!vowel(b[b.size()-1])) && (b[b.size()-1]!='n')) correct=0;
    if(correct) cout << "YES" << endl;
    else cout << "NO";
    return 0;
}

bool vowel(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return 1;
    return 0;
}