Var n, m, a, b, c, i: longint;
    s1, s2: String;
    bo: boolean;
Begin
    ReadLn(n);
    if n >= 3 then bo := true else bo := false;
    dec(n);
    a := ( ( (n-1) div 3 ) + 1);
    if n < 0 then a := 0;
    dec(n);
    b := ( ( (n-1) div 3 ) + 1);
    if n < 0 then b := 0;
    dec(n);
    c := ( ( (n-1) div 3 ) + 1);
    if n < 1 then c := 0;
    WriteLn('+------------------------+');
    Write('|');
    for i:=1 to 11 do
    begin
        if a > 0 then Write('O.') else Write('#.');
        dec(a);
    end;
    WriteLn('|D|)');
    Write('|');
    for i:=1 to 11 do
    begin
        if b > 0 then Write('O.') else Write('#.');
        dec(b);
    end;
    WriteLn('|.|');
    Write('|');
    if bo then Write('O') else Write('#');
    WriteLn('.......................|');
    Write('|');
    for i:=1 to 11 do
    begin
        if c > 0 then Write('O.') else Write('#.');
        dec(c);
    end;
    WriteLn('|.|)');
    WriteLn('+------------------------+');
End.