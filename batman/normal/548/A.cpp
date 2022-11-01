    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    #include <stack>
    #include <queue>
    #include <string>
    #include <map>
    #include <cstring>
    #include <vector>
    #define MAX 100005
    using namespace std;
     
    int main()
    {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int l = s.size();
    bool flag = false;
    if(l % k!=0)
    cout << "NO";
    else{
    int step = k, d = l / k;
    int pos = 0;
    for(int i = 1; i <= step; i++){
    for(int j = pos, v = d + pos - 1; j < d + pos - 1; j++, v--){
     
    if(s[j] != s[v]){
    cout << "NO";
    return 0;
    }
    }
    pos += d;
    }
    cout << "YES";
    }
    return 0;
    }