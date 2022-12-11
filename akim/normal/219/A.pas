var n,i:longint;
    s,t:ansistring;
    a:array['a'..'z']of longint;
    c:char;
begin
 readln(n);
 readln(s);
 for i:=1 to length(s) do
  inc(a[s[i]]);
 t:='';
 for c:='a' to 'z' do
  if a[c] mod n=0 then begin for i:=1 to a[c]div n do t:=t+c;end else begin writeln('-1');halt(0);end;
 for i:=1 to n do
  write(t);
 writeln;
end.