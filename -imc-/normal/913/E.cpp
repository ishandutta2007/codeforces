#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

struct Expr {
    string s;
    
    // mask < 2^8=256
    int value;
    
    // 0 = constant, 1 = NOT, 2 = AND, 3 = OR
    //int priority;
    
    string wrap(bool wrap) const { if (wrap) return "(" + s + ")"; else return s; }
};

void solve(bool read) {
    map<int, string> ans;
    
ans[0] = "!x&x";
ans[1] = "!(x|y|z)";
ans[2] = "!y&!z&x";
ans[3] = "!y&!z";
ans[4] = "!x&!z&y";
ans[5] = "!x&!z";
ans[6] = "!(!x&!y|x&y|z)";
ans[7] = "!(x&y|z)";
ans[8] = "!z&x&y";
ans[9] = "!(!x&y|!y&x|z)";
ans[10] = "!z&x";
ans[11] = "!(!x&y|z)";
ans[12] = "!z&y";
ans[13] = "!(!y&x|z)";
ans[14] = "!z&(x|y)";
ans[15] = "!z";
ans[16] = "!x&!y&z";
ans[17] = "!x&!y";
ans[18] = "!(!x&!z|x&z|y)";
ans[19] = "!(x&z|y)";
ans[20] = "!(!y&!z|x|y&z)";
ans[21] = "!(x|y&z)";
ans[22] = "!(!x&!y|x&y|z)|!x&!y&z";
ans[23] = "!((x|y)&z|x&y)";
ans[24] = "!x&!y&z|!z&x&y";
ans[25] = "!x&!y|!z&x&y";
ans[26] = "!x&!y&z|!z&x";
ans[27] = "!x&!y|!z&x";
ans[28] = "!x&!y&z|!z&y";
ans[29] = "!x&!y|!z&y";
ans[30] = "!x&!y&z|!z&(x|y)";
ans[31] = "!x&!y|!z";
ans[32] = "!y&x&z";
ans[33] = "!(!x&z|!z&x|y)";
ans[34] = "!y&x";
ans[35] = "!(!x&z|y)";
ans[36] = "!x&!z&y|!y&x&z";
ans[37] = "!x&!z|!y&x&z";
ans[38] = "!x&!z&y|!y&x";
ans[39] = "!x&!z|!y&x";
ans[40] = "!y&x&z|!z&x&y";
ans[41] = "!(!x&y|!y&x|z)|!y&x&z";
ans[42] = "!(y&z)&x";
ans[43] = "!(!x&y|z)|!y&x";
ans[44] = "!y&x&z|!z&y";
ans[45] = "!(!y&x|z)|!y&x&z";
ans[46] = "!y&x|!z&y";
ans[47] = "!y&x|!z";
ans[48] = "!y&z";
ans[49] = "!(!z&x|y)";
ans[50] = "!y&(x|z)";
ans[51] = "!y";
ans[52] = "!x&!z&y|!y&z";
ans[53] = "!x&!z|!y&z";
ans[54] = "!x&!z&y|!y&(x|z)";
ans[55] = "!x&!z|!y";
ans[56] = "!y&z|!z&x&y";
ans[57] = "!(!z&x|y)|!z&x&y";
ans[58] = "!y&z|!z&x";
ans[59] = "!y|!z&x";
ans[60] = "!y&z|!z&y";
ans[61] = "!(!y&!z&x|y&z)";
ans[62] = "!y&(x|z)|!z&y";
ans[63] = "!y|!z";
ans[64] = "!x&y&z";
ans[65] = "!(!y&z|!z&y|x)";
ans[66] = "!x&y&z|!y&!z&x";
ans[67] = "!x&y&z|!y&!z";
ans[68] = "!x&y";
ans[69] = "!(!y&z|x)";
ans[70] = "!x&y|!y&!z&x";
ans[71] = "!x&y|!y&!z";
ans[72] = "!x&y&z|!z&x&y";
ans[73] = "!(!x&y|!y&x|z)|!x&y&z";
ans[74] = "!x&y&z|!z&x";
ans[75] = "!(!x&y|z)|!x&y&z";
ans[76] = "!(x&z)&y";
ans[77] = "!(!y&x|z)|!x&y";
ans[78] = "!x&y|!z&x";
ans[79] = "!x&y|!z";
ans[80] = "!x&z";
ans[81] = "!(!z&y|x)";
ans[82] = "!x&z|!y&!z&x";
ans[83] = "!x&z|!y&!z";
ans[84] = "!x&(y|z)";
ans[85] = "!x";
ans[86] = "!x&(y|z)|!y&!z&x";
ans[87] = "!x|!y&!z";
ans[88] = "!x&z|!z&x&y";
ans[89] = "!(!z&y|x)|!z&x&y";
ans[90] = "!x&z|!z&x";
ans[91] = "!(!x&!z&y|x&z)";
ans[92] = "!x&z|!z&y";
ans[93] = "!x|!z&y";
ans[94] = "!x&(y|z)|!z&x";
ans[95] = "!x|!z";
ans[96] = "!x&y&z|!y&x&z";
ans[97] = "!(!x&z|!z&x|y)|!x&y&z";
ans[98] = "!x&y&z|!y&x";
ans[99] = "!(!x&z|y)|!x&y&z";
ans[100] = "!x&y|!y&x&z";
ans[101] = "!(!y&z|x)|!y&x&z";
ans[102] = "!x&y|!y&x";
ans[103] = "!(!x&!y&z|x&y)";
ans[104] = "!x&y&z|!y&x&z|!z&x&y";
ans[105] = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
ans[106] = "!(y&z)&x|!x&y&z";
ans[107] = "!(!x&y|z)|!x&y&z|!y&x";
ans[108] = "!(x&z)&y|!y&x&z";
ans[109] = "!(!y&x|z)|!x&y|!y&x&z";
ans[110] = "!(x&z)&y|!y&x";
ans[111] = "!x&y|!y&x|!z";
ans[112] = "!(x&y)&z";
ans[113] = "!(!z&x|y)|!x&z";
ans[114] = "!x&z|!y&x";
ans[115] = "!x&z|!y";
ans[116] = "!x&y|!y&z";
ans[117] = "!x|!y&z";
ans[118] = "!x&(y|z)|!y&x";
ans[119] = "!x|!y";
ans[120] = "!(x&y)&z|!z&x&y";
ans[121] = "!(!z&x|y)|!x&z|!z&x&y";
ans[122] = "!(x&y)&z|!z&x";
ans[123] = "!x&z|!y|!z&x";
ans[124] = "!(x&y)&z|!z&y";
ans[125] = "!x|!y&z|!z&y";
ans[126] = "!x&y|!y&z|!z&x";
ans[127] = "!(x&y&z)";
ans[128] = "x&y&z";
ans[129] = "!(x|y|z)|x&y&z";
ans[130] = "!y&!z&x|x&y&z";
ans[131] = "!y&!z|x&y&z";
ans[132] = "!x&!z&y|x&y&z";
ans[133] = "!x&!z|x&y&z";
ans[134] = "!(!x&!y|x&y|z)|x&y&z";
ans[135] = "!(x&y|z)|x&y&z";
ans[136] = "x&y";
ans[137] = "!(x|y|z)|x&y";
ans[138] = "!z&x|x&y";
ans[139] = "!y&!z|x&y";
ans[140] = "!z&y|x&y";
ans[141] = "!x&!z|x&y";
ans[142] = "!z&(x|y)|x&y";
ans[143] = "!z|x&y";
ans[144] = "!x&!y&z|x&y&z";
ans[145] = "!x&!y|x&y&z";
ans[146] = "!(!x&!z|x&z|y)|x&y&z";
ans[147] = "!(x&z|y)|x&y&z";
ans[148] = "!(!y&!z|x|y&z)|x&y&z";
ans[149] = "!(x|y&z)|x&y&z";
ans[150] = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
ans[151] = "!((x|y)&z|x&y)|x&y&z";
ans[152] = "!x&!y&z|x&y";
ans[153] = "!x&!y|x&y";
ans[154] = "!x&!y&z|!z&x|x&y";
ans[155] = "!(x&z|y)|x&y";
ans[156] = "!x&!y&z|!z&y|x&y";
ans[157] = "!(x|y&z)|x&y";
ans[158] = "!x&!y&z|!z&(x|y)|x&y";
ans[159] = "!x&!y|!z|x&y";
ans[160] = "x&z";
ans[161] = "!(x|y|z)|x&z";
ans[162] = "!y&x|x&z";
ans[163] = "!y&!z|x&z";
ans[164] = "!x&!z&y|x&z";
ans[165] = "!x&!z|x&z";
ans[166] = "!x&!z&y|!y&x|x&z";
ans[167] = "!(x&y|z)|x&z";
ans[168] = "(y|z)&x";
ans[169] = "!(x|y|z)|(y|z)&x";
ans[170] = "x";
ans[171] = "!y&!z|x";
ans[172] = "!z&y|x&z";
ans[173] = "!(!y&x|z)|x&z";
ans[174] = "!z&y|x";
ans[175] = "!z|x";
ans[176] = "!y&z|x&z";
ans[177] = "!x&!y|x&z";
ans[178] = "!y&(x|z)|x&z";
ans[179] = "!y|x&z";
ans[180] = "!x&!z&y|!y&z|x&z";
ans[181] = "!(x|y&z)|x&z";
ans[182] = "!x&!z&y|!y&(x|z)|x&z";
ans[183] = "!x&!z|!y|x&z";
ans[184] = "!y&z|x&y";
ans[185] = "!(!z&x|y)|x&y";
ans[186] = "!y&z|x";
ans[187] = "!y|x";
ans[188] = "!y&z|!z&y|x&y";
ans[189] = "!x&!y|!z&y|x&z";
ans[190] = "!y&z|!z&y|x";
ans[191] = "!y|!z|x";
ans[192] = "y&z";
ans[193] = "!(x|y|z)|y&z";
ans[194] = "!y&!z&x|y&z";
ans[195] = "!y&!z|y&z";
ans[196] = "!x&y|y&z";
ans[197] = "!x&!z|y&z";
ans[198] = "!x&y|!y&!z&x|y&z";
ans[199] = "!(x&y|z)|y&z";
ans[200] = "(x|z)&y";
ans[201] = "!(x|y|z)|(x|z)&y";
ans[202] = "!z&x|y&z";
ans[203] = "!(!x&y|z)|y&z";
ans[204] = "y";
ans[205] = "!x&!z|y";
ans[206] = "!z&x|y";
ans[207] = "!z|y";
ans[208] = "!x&z|y&z";
ans[209] = "!x&!y|y&z";
ans[210] = "!x&z|!y&!z&x|y&z";
ans[211] = "!(x&z|y)|y&z";
ans[212] = "!x&(y|z)|y&z";
ans[213] = "!x|y&z";
ans[214] = "!x&(y|z)|!y&!z&x|y&z";
ans[215] = "!x|!y&!z|y&z";
ans[216] = "!x&z|x&y";
ans[217] = "!(!z&y|x)|x&y";
ans[218] = "!x&z|!z&x|x&y";
ans[219] = "!x&!y|!z&x|y&z";
ans[220] = "!x&z|y";
ans[221] = "!x|y";
ans[222] = "!x&z|!z&x|y";
ans[223] = "!x|!z|y";
ans[224] = "(x|y)&z";
ans[225] = "!(x|y|z)|(x|y)&z";
ans[226] = "!y&x|y&z";
ans[227] = "!(!x&z|y)|y&z";
ans[228] = "!x&y|x&z";
ans[229] = "!(!y&z|x)|x&z";
ans[230] = "!x&y|!y&x|x&z";
ans[231] = "!x&!z|!y&x|y&z";
ans[232] = "(x|y)&z|x&y";
ans[233] = "!(x|y|z)|(x|y)&z|x&y";
ans[234] = "x|y&z";
ans[235] = "!y&!z|x|y&z";
ans[236] = "x&z|y";
ans[237] = "!x&!z|x&z|y";
ans[238] = "x|y";
ans[239] = "!z|x|y";
ans[240] = "z";
ans[241] = "!x&!y|z";
ans[242] = "!y&x|z";
ans[243] = "!y|z";
ans[244] = "!x&y|z";
ans[245] = "!x|z";
ans[246] = "!x&y|!y&x|z";
ans[247] = "!x|!y|z";
ans[248] = "x&y|z";
ans[249] = "!x&!y|x&y|z";
ans[250] = "x|z";
ans[251] = "!y|x|z";
ans[252] = "y|z";
ans[253] = "!x|y|z";
ans[254] = "x|y|z";
ans[255] = "!x|x";
// 256 ok


    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string mask;
        cin >> mask;
        int our_mask = 0;
        for (int j = 0; j < 8; j++) {
            int x = j / 4, y = (j / 2) & 1, z = j & 1;
            
            if (mask[j] == '1')
                our_mask |= (1 << (x + 2 * y + 4 * z));
        }
        
        cout << ans[our_mask] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //solve(false);
    
    return 0;
}