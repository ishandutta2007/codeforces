Program arsijo;
Var n, m, i, j: longint;
Begin
    Read(n, m);
    WriteLn(n + m - 1);
    for i:=1 to m do
        WriteLn('1 ', i);
    for i:=2 to n do
        WriteLn(i, ' 1');
End.