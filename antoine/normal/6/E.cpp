
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <deque>
#include <vector>

long long n, k;
long long h[100000];

class sWindow {
    std::deque<std::pair<int, long long>> s;
    
    virtual bool cmp(long long &a, long long &b)=0;
    
    public: void add(int i, long long v) {
        while(s.size() > 0 && cmp(s.front().second, v))
            s.pop_front();
        s.push_front({i, v});
    }
    public: void setFromIdx(int i) {
        while(s.back().first < i)
            s.pop_back();
    }
    public: long long extremum() {
        return s.back().second;
    }
};

class minWindow : public sWindow {
    bool cmp(long long &a, long long &b) {
        return a >= b;
    }
};

class maxWindow  : public sWindow {
    bool cmp(long long &a, long long &b) {
        return a <= b;
    }
};

class minMaxWindow {
    minWindow minW;
    maxWindow maxW;
    
    public: void add(int i, long long v) {
        minW.add(i, v);
        maxW.add(i, v);
    }
    
public: void setFromIdx(int i) {
    minW.setFromIdx(i);
    maxW.setFromIdx(i);
}
    
public: long long min() {
    return minW.extremum();
}

public: long long max() {
    return maxW.extremum();
}
public: long long range() {
    return max() - min();
}
};

int main() {
    std::cin >> n >> k;
    for(int i = 0; i < n; ++i)
        std::cin >> h[i];
    
    minMaxWindow mMW;
    int a = 0;
    std::vector<std::pair<int, int>> vec;
    int i = 0;
    for(int j = 0; j < n; ++j) {
        mMW.add(j, h[j]);
        while(mMW.range() > k) {
            mMW.setFromIdx(++i);
        }
        int count = j - i + 1;
        if(count >= a) {
            if(count != a)
                vec.clear();
            a = count;
            vec.push_back({i, j});
        }
    }
    std::cout << a << " " << vec.size();
    for(auto p : vec) {
        std::cout << "\n" << (p.first + 1) << " " << (p.second + 1);
    }
    return 0;
}