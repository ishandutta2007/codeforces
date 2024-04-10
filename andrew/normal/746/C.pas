var x1,x2,q,q1,t1,t2,s,p,d:longint;
begin
 read(s,x1,x2,t1,t2,p,d);
 if x1>x2 then begin x1:=-x1;x2:=-x2;p:=-p;d:=-d;end;
 if d=1 then begin
  q:=(x2-x1)*t2;
  if p<=x1 then q1:=(x2-p)*t1 else if x2<p then q1:=2*s*t1-t1*(p-x2) else
  q1:=2*s*t1+t1*(x2-p);
  if q<q1 then write(q) else write(q1);
 end else begin
 q:=(x2-x1)*t2;if p>=0 then q1:=(p+x2)*t1 else q1:=(s+s+p+x2)*t1;
 if q<q1 then write(q) else write(q1);
 end;
end.