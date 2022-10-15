Var a, c, n, i, j: longint;
    ar: array [1..6] of longint;
Begin
    for i:=1 to 6 do Read(ar[i]);
    for i:=1 to 5 do
        for j:=i+1 to 6 do
            if ar[i] < ar[j] then
            begin
                c := ar[i];
                ar[i] := ar[j];
                ar[j] := c;
            end;
    //if ar[1] = ar[6] then WriteLn('Alien') else
    if ar[1] = ar[4] then
    begin
        if ar[5] = ar[6] then WriteLn('Elephant') else Writeln('Bear');
    end else if ar[3] = ar[6] then
    begin
        if ar[1] = ar[2] then WriteLn('Elephant') else Writeln('Bear');
    end else if (ar[1] <> ar[2]) and (ar[2] = ar[5]) and (ar[5] <> ar[6]) then
        Writeln('Bear') else WriteLn('Alien');
End.