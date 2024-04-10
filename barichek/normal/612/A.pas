uses math;
var
  s:ansistring;
  p,q,ap,aq:longint;
  i,j,l:longint;
  ok:boolean;
begin
  readln(p,p,q);
  read(s);

  for i:=0 to length(s) div p do
    if (length(s)-i*p)mod q=0 then
      begin
        j:=(length(s)-i*p)div q;
        ok:=true;
        break;
      end;

  if not ok then begin writeln(-1); halt; end;

  writeln(i+j);
  l:=1;

  if i<>0 then
  repeat
    writeln(copy(s,l,p));
    inc(l,p);
    dec(i);
  until i=0;

  if j<>0 then
  repeat
    writeln(copy(s,l,q));
    inc(l,q);
    dec(j);
  until j=0

end.