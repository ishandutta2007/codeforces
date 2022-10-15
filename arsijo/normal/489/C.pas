Program arsijo;
Var a, b, c, d, e, i, j, n, m, max, min: longint;
Procedure goAway;
Begin
    WriteLn('-1 -1');
    halt;
End;
Begin
    Read(n, m);
    a := m div 9;
    b := m mod 9;
    if b = 0 then
        d := 0 else
        d := 1;

    c := n - a - d;
    if n = 1 then
    begin
        if m < 10 then
                WriteLn(m, ' ', m) else
                goAway;
        exit;
    end;
    if a = n then
    begin
        if d = 1 then
            goAway;
        for i:=1 to a do
                Write(9);
        Write(' ');
        for i:=1 to a do
                Write(9);
                exit;
        exit;
    end;
    if c < 0 then goAway;
    if m = 0 then
    begin
        if n = 1 then
                WriteLn('0 0') else
                goAway;
        exit;
    end;
    
    if (c <> 0) and ( (b <> 0) or (a <> 0) ) then
    begin
        if (b <> 0) then
        begin
                Write(1);
                for i:=1 to (c-1) do
                        Write(0);
                Write(b-1);
                for i:=1 to a do
                        Write(9);
        end else
        begin
                Write(1);
                for i:=1 to (c-1) do
                        Write(0);
                Write(8);
                for i:=1 to (a-1) do
                        Write(9);
        end;
    end else
    begin
        Write(b);
        for i:=1 to a do
                Write(9);
    end;
    write(' ');
    for i:=1 to a do
        Write(9);
    if d = 1 then Write(b);
    for i:=1 to c do
        Write(0);
End.