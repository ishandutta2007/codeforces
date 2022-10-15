Program arsijo;
Var n, i, j, m, min, a, b, c: longint;
        ar: array [1..50] of longint;
Begin
    Read(n, a);
    c := 0;
    for i:=1 to n do
    begin
        Read(m);
        Read(min);
        for j:=2 to m do
        begin
                Read(b);
                if b < min then min := b;
        end;
        if min < a then
        begin
                inc(c);
                ar[c] := i;
        end;
    end;
    WriteLn(c);
    for i:=1 to c do
        Write(ar[i], ' ');
End.