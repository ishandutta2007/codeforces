var x1,y1,r1,rr1,x2,y2,r2,rr2,q:longint;s:extended;
begin
 readln(x1,y1,r1,rr1);
 readln(x2,y2,r2,rr2);
 s:=sqrt(sqr(x1-x2)+sqr(y1-y2));q:=0;
 if (s>=r1+r2)and(s>=r1+rr2)then inc(q);
 if (r2>=s+r1)and(rr2>=s+r1)then inc(q);
 if (r1>=s+r2)and(r1>=s+rr2)then inc(q);

 if (s>=rr1+r2)and(s>=rr1+rr2)then inc(q);
 if (r2>=s+rr1)and(rr2>=s+rr1)then inc(q);
 if (rr1>=s+r2)and(rr1>=s+rr2)then inc(q);

 if (s>=r2+r1)and(s>=r2+rr1)then inc(q);
 if (r1>=s+r2)and(rr1>=s+r2)then inc(q);
 if (r2>=s+r1)and(r2>=s+rr1)then inc(q);

 if (s>=rr2+r1)and(s>=rr2+rr1)then inc(q);
 if (r1>=s+rr2)and(rr1>=s+rr2)then inc(q);
 if (rr2>=s+r1)and(rr2>=s+rr1)then inc(q);
 writeln(q);
end.