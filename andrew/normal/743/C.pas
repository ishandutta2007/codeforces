var n:int64;
begin
  readln(n);
  if n=1 then begin
                 writeln('-1');
                 halt;
               end;
  writeln(n,' ',n+1,' ',n*(n+1));
end.