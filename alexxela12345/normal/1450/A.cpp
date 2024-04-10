#include <bits/stdc++.h>
using namespace std;

const int BUF_SIZE = 4096;

// INPUT

char BUFIN[BUF_SIZE];
int inpos = 0;
int inlen = 0;

bool isEof() {
    if (inpos == inlen) {
        inlen = fread(BUFIN, 1, BUF_SIZE, stdin);
        inpos = 0;
    }
    return inpos == inlen;
}

char getChar() {
    if (isEof()) {
        return -1;
    }
    return BUFIN[inpos++];
}

char readChar() {
    char c = getChar();
    while (c <= ' ') {
        c = getChar();
    }
    return c;
}

int readInt() {
    char c = readChar();
    int sign = 1;
    if (c == '-') {
        sign = -1;
       c = getChar(); 
    }
    int num = 0;
    while (c > ' ') {
        num *= 10;
        num += c - '0';
        c = getChar();
    }
    return num * sign;
}

string readString() {
    string ans = "";
    char c = readChar();
    while (c > ' ') {
        ans.push_back(c);
        c = getChar();
    }
    return ans; 
}

// OUT

char BUFOUT[BUF_SIZE];
int posout = 0;

void writeChar(char c) {
    if (posout == BUF_SIZE) {
       fwrite(BUFOUT, 1, posout, stdout);
       posout = 0;
    }
    BUFOUT[posout++] = c; 
}

void flush() {
    if (posout) {
       fwrite(BUFOUT, 1, posout, stdout);
    }
}

void writeString(string s) {
    for (char c : s)
        writeChar(c);
}

char BKEK[20];

void writeInt(int n) {
    if (n < 0) {
        writeChar('-');
        n = -n;
    }
    int pos = 0;
    while (n) {
        BKEK[pos++] = n % 10;
        n /= 10;
    }
    if (pos == 0)
        pos = 1;
    while (pos--)
        writeChar(BKEK[pos]);
}

int main() {
    int n = readInt();
    while (n--) {
        int ln = readInt();
        string s = readString();
        sort(s.begin(), s.end());
        writeString(s);
        writeChar('\n');
    }
    flush();
}