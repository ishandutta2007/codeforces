Program arsijo;
uses math;
Var i, e, d, a, b, len, t: longint;
        s: ansiString;
        bol: boolean;
        ar: array [1..100000] of longint;
Begin
    t := 0;
    e := 0;
    d := 0;
    ReadLn(s);
    len := 0;
    bol := false;
    for i:=1 to length(s) do
    begin
        if s[i] = '(' then
                inc(e) else dec(e);
        if s[i] = '#' then
                ar[i] := 1;
        if e < 0 then
        begin
            WriteLn(-1);
            exit;
        end;
    end;

    i := length(s);

    while s[i] <> '#' do
        dec(i);

    ar[i] := e + 1;

    e:=0;

    for i:=1 to length(s) do
    begin
        if s[i] = '(' then
                inc(e) else
        if s[i] = ')' then
                dec(e) else
                dec(e, ar[i]);
        if e < 0 then
        begin
            WriteLn(-1);
            exit;
        end;
    end;
    for i:=1 to length(s) do
        if s[i] = '#' then
                WriteLn(ar[i]);
End.