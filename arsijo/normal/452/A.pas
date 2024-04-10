Program arsijo;
Const ar: array [1..6] of String = ('jolteon', 'flareon', 'umbreon', 'leafeon', 'glaceon', 'sylveon');
Var n: longint;
        s: String;
        b: array [1..6] of boolean;
Function findAnswer: String;
Var i, a, c, j: longint;
Begin
    if n = 6 then exit('espeon');
    if n = 8 then exit('vaporeon');
    for i:=1 to 6 do
        b[i] := false;
    a := 6;
    for i:=1 to 7 do
    begin
        if s[i] = '.' then
                continue;
        for j:=1 to 6 do
                if not(b[j]) and (s[i] <> ar[j, i]) then
                begin
                    dec(a);
                    b[j] := true;
                    if a = 1 then
                    begin
                        for c := 1 to 6 do
                                if not(b[c]) then
                                        exit(ar[c]);
                    end;
                end;
    end;
    for c := 1 to 6 do
        if not(b[c]) then
                exit(ar[c]);
End;
Begin
    ReadLn(n);
    ReadLn(s);
    WriteLn(findAnswer);
End.