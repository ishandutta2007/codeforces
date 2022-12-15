var
 c,s11,s12,s21,s22,p11,p12,p21,p22:char;
 s1,s2,p3,d1,d2,d3,s3,p1,p2,n,i,s,l,k,j,v:longint;
begin
 readln(p11,p12,c,p21,p22);
 p1:=(ord(p11)-48)*10+(ord(p12)-48);
 p2:=(ord(p21)-48)*10+(ord(p22)-48);
 p3:=p1*60+p2;
 readln(s11,s12,c,s21,s22);
 s1:=(ord(s11)-48)*10+(ord(s12)-48);
 s2:=(ord(s21)-48)*10+(ord(s22)-48);
 s3:=s1*60+s2;
 d3:=p3-s3 ;
 if d3<0 then d3:=d3+1440 ;
 d1:=d3 div 60;
 d2:=d3 mod 60;
 if d1<10 then write(0,d1,':') else write(d1,':');
 if d2<10 then writeln(0,d2) else writeln(d2);
end.