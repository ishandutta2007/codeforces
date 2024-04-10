Program arsijo;
Var i, j: longint;
        s: string;
        bo: boolean;
        ar: array [1..3] of longint;
Begin
    ReadLn(s);
    bo := false;
    for i:=1 to length(s) do
    begin
        if bo then
        begin
            bo := false;
            continue;
        end;
        bo := true;
        case s[i] of
        '1': inc(ar[1]);
        '2': inc(ar[2]);
        '3': inc(ar[3]);
        end;
    end;
    bo := true;
    for i :=1 to 3 do
        for j:=1 to ar[i] do
        begin
            if bo then
            begin
                bo := false;
                Write(i);
            end else
                Write('+', i);
        end;
End.