Program arsijo;
Var n, a, b, i: longint;
Begin
    Read(n);
    for i:=1 to n do
    begin
        Read(a, b);
        if a <> b then
        begin
            WriteLn('Happy Alex');
            exit;
        end;
    end;
    WriteLn('Poor Alex');
End.