#include<bits/stdc++.h>

using namespace std;

//     (  0 -  0)

string f(string s) {
    string ans = "";
    for (auto c : s) {
        if ((int)ans.size() > 0 || c != '0') ans += c;
    }
    if ((int)ans.size() == 0) ans += "0";
    return ans;
}

//    

string sum(string A, string B) {
    string ans = "";
    string add = "";
    for (int i = 0; i < (int)A.size() - (int)B.size(); ++i) add += "0";
    B = add + B;
    add = "";
    for (int i = 0; i < (int)B.size() - (int)A.size(); ++i) add += "0";
    A = add + A;
    int val = 0;
    for (int i = (int)A.size() - 1; i >= 0; --i) {
        val = val + A[i] - '0' + B[i] - '0';
        ans += char('0' + val % 10);
        val = val / 10;
    }
    ans += char('0' + val);
    reverse(ans.begin(), ans.end());
    ans = f(ans);
    return ans;
}

//   

string del(string A, string B) {
    if (A == B) return "0";
    int ok = 0;
    if ((int)A.size() > (int)B.size() || ((int)A.size() == (int)B.size() && A > B)) ok = 1;
    else swap(A, B);
    string ans = "", add = "";
    for (int i = 0; i < (int)A.size() - (int)B.size(); ++i) add += "0";
    B = add + B;
    int val = 0;
    for (int i = (int)A.size() - 1; i >= 0; --i) {
        val = val + A[i] - '0' - (B[i] - '0');
        if (val < 0) {
            ans += char('0' + val + 10);
            val = -1;
        }
        else ans += char('0' + val), val = 0;
    }
    reverse(ans.begin(), ans.end());
    ans = f(ans);
    if (!ok) ans = "-" + ans;
    return ans;
}

///   

string get(string A, char t, string B) {
    if (B[0] == '-' && t == '-') {
        t = '+';
        string new_B = "";
        for (int i = 1; i < (int)B.size(); ++i) new_B += B[i];
        B = new_B;
    }
    if (A[0] == '-' && B[0] == '-') {
        string new_A = "", new_B = "";
        for (int i = 1; i < (int)A.size(); ++i) new_A += A[i];
        for (int i = 1; i < (int)B.size(); ++i) new_B += B[i];
        return "-" + sum(new_A, new_B);
    }
    if (A[0] != '-' && B[0] != '-') {
        if (t == '+') return sum(A, B);
        return del(A, B);
    }
    if (B[0] == '-') {
        string new_B = "";
        for (int i = 1; i < (int)B.size(); ++i) new_B += B[i];
        return del(A, new_B);
    }
    if (A[0] == '-' && t == '+') {
        string new_A = "";
        for (int i = 1; i < (int)A.size(); ++i) new_A += A[i];
        return del(B, new_A);
    }
    string new_A = "";
    for (int i = 1; i < (int)A.size(); ++i) new_A += A[i];
    return "-" + sum(new_A, B);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string A, B;
    char t;
    int T;
    cin >> T;
    while (T--) {
    cin >> A >> B;
    if (B[0] == '-') t = '+';
    else B = "-" + B, t = '-';
    cout << get(A, t, B) << '\n';
    }
    return 0;
}