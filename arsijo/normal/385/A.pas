Program arsijo;
uses math;
Var n, c, i, m, a, b: longint;
Begin
    Read(n, c);
    Read(a);
    m := 0;
    for i:=2 to n do
    begin
        Read(b);
        m := max(m, a - b - c);
        a := b;
    end;
    WriteLn(m);
End.