Var a, b, c, i, n, m: longint;
Begin
    Read(n, m);
    for i:=(n div 2) downto 0 do
    begin
        if (i + (n - (i * 2))) mod m = 0 then
        begin
            WriteLn(i + (n - (i * 2)));
            exit;
        end;
    end;
    WriteLn(-1);
End.