#!/bin/python

import re

def solve():
    n = int(input())
    names = input().split()
    m = int(input())
    mess = []
    for i in range(m):
        s = input().split(":")
        mess.append(s)
    while True:
        flg = False
        for i in range(m):
            if mess[i][0] != '?':
                continue
            poss = []
            for name in names:
                if (i == 0 or name != mess[i-1][0]) and (i == m-1 or name != mess[i+1][0]) and (name not in re.split("\W+", mess[i][1])):
                    poss.append(name)
            if len(poss) == 0:
                print('Impossible')
                return
            if len(poss) == 1:
                mess[i][0] = poss[0]
                flg = True
        if not flg:
            break
    for i in range(m):
        if mess[i][0] != '?':
            continue
        for name in names:
            if (i == 0 or name != mess[i-1][0]) and (i == m-1 or name != mess[i+1][0]) and (name not in re.split("\W+", mess[i][1])):
                mess[i][0] = name
                break
    for name, mes in mess:
       print(name + ':' + mes)
    return

for _ in range(int(input())):
    solve()