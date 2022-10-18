uses math;
var
  n,a,b:longint;
begin
  read(n,a,b);
  while b<>0 do
    begin
      if b>0 then
        if a=n then
          begin
            a:=1;
            dec(b);
          end
        else
          begin
            inc(a);
            dec(b);
          end;
      if b<0 then
        if a=1 then
          begin
            a:=n;
            inc(b);
          end
        else
          begin
            dec(a);
            inc(b);
          end;
    end;

  writeln(a);
end.