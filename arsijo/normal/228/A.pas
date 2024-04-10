Program arsijo;
Var a, i, j, l: longint;
        ar: array [1..4] of longint;
        bol: boolean;
Begin
    for i:=1 to 4 do
    begin
        bol := true;
        Read(a);
        for j:=1 to l do
                if ar[j] = a then
                begin
                    bol := false;
                    break;
                end;
        if bol then
        begin
                inc(l);
                ar[l] := a;
        end;
    end;
    WriteLn( 4 - l );
End.