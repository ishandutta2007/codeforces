Program arsijo;
Var n, last, i, a, b: longint;
Begin
    Read(n);
    b := 1;
    Read(last);
    for i:=2 to n do
    begin
        Read(a);
        if a <> last then
                inc(b);
        last := a;
    end;
    WriteLn(b);
End.