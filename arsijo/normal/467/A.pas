Var a, p, q, n, i: longint;
Begin
    Readln(n);
    for i:=1 to n do
    begin
        Read(p, q);
        if q - p >= 2 then inc(a);
    end;
    WriteLn(a);
End.