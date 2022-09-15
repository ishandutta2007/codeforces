#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isNum(string s)
{
    if(s == "") return false;
    if(s == "0") return true;
    if(s[0] == '0') return false;
    for(char c: s)
        if(!('0' <= c && c <= '9')) return false;
    return true;
}

string tos(vector<string> V)
{
    if(V.size() == 0) return "-";
    string ans = "\"";
    for(string s: V) ans += s + ',';
    ans.back() = '"';
    return ans;
}

int main()
{
    string s; cin >> s;
    vector<string> num, str;
    string cur = "";
    for(char c: s)
    {
        if(c == ',' || c == ';')
        {
            if(isNum(cur)) num.push_back(cur);
            else str.push_back(cur);
            cur = "";
        }
        else cur += c;
    }
    if(isNum(cur)) num.push_back(cur);
    else str.push_back(cur);
    cout << tos(num) << endl << tos(str) << endl;
}