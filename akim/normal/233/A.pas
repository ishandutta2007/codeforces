var n,i:longint;
begin
 readln(n);
 if n mod 2=1 then begin writeln('-1');halt(0);end;
 for i:=1 to n do
 if i<=n div 2 then write(i+n div 2,' ') else write(i-n div 2,' ');
end.