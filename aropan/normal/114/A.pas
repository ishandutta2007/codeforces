var
    k, l, x: longint;
begin
    read(k, l);
    x := 0;
    while l mod k = 0 do
        begin
            l := l div k;
            x := x + 1;
        end;
    if (l = 1) then
        begin
            writeln('YES');
            writeln(x - 1);
        end
    else
        begin
            writeln('NO');
        end;
end.